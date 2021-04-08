import os
import logging, logging.config
from datetime import datetime

import subprocess
import time

from utils.bash_utils import linux_which

SYNC = linux_which('sync')

class ScriptLogger(object):

    main_logger = None

    def __init__(self, script_file, extra_info=None, fmt="%Y%m%d_%H%M%S", debug=True, mute_console=False):
        self.log_time = None
        if ScriptLogger.main_logger is not None:
            return
        else:
            handlers = ['console', 'file']
            if mute_console:
                handlers.remove('console')
            if debug:
                level = 'DEBUG'
            else:
                level = 'INFO'
            self.log_file = os.path.basename(script_file)[0:-3]
            if extra_info:
                self.log_file = "{}_{}".format(self.log_file, extra_info)
            self.log_time = datetime.now().strftime(fmt)
            self.log_file = "{}_{}".format(self.log_file, self.log_time)

            LOGGING = {
                'version': 1,
                'disable_existing_loggers': False,
                'formatters': {
                    'verbose': {
                        'format': '%(name)s %(levelname)s %(asctime)s %(module)s %(lineno)d %(thread)d %(message)s'
                    },
                    'simple': {
                        'format': '%(name)s %(levelname)s %(message)s'
                    },
                },
                'handlers': {
                    'console': {
                        'level': level,
                        'class': 'logging.StreamHandler',
                        'formatter': 'verbose'
                    },
                    'file': {
                        'level': level,
                        'class': 'logging.handlers.TimedRotatingFileHandler',
                        'filename': '{}.log'.format(self.log_file),
                        'formatter': 'verbose',
                        'when': 'midnight',
                        'backupCount': 30,
                        'delay': False
                    },
                },

                'loggers': {
                    # Might as well log any errors anywhere else in Django
                    '__main__': {
                        'handlers': handlers,
                        'level': level,
                        'propagate': True,
                    }
                }
            }

            logging.config.dictConfig(LOGGING)
            ScriptLogger.main_logger = logging.getLogger('__main__')

    @classmethod
    def get_main_logger(cls):
        if ScriptLogger.main_logger is None:
            raise RuntimeError("Logger was not configured (did you call the constructor?)")

        return ScriptLogger.main_logger

    def get_log_file_preffix(self):
        return self.log_file

    @classmethod
    def flush_all_handlers(cls):
        for h in cls.main_logger.handlers:
            h.flush()
        # Call sync into os level
        subprocess.check_output(SYNC, shell=True, stderr=subprocess.STDOUT)

    pass



def follow_file(file_obj):
    """
    Based on the amazing guide http://www.dabeaz.com/generators/Generators.pdf
    Works as tailf -f

    :param file_obj:
    :return:
    """
    file_obj.seek(0, os.SEEK_END)  # End-of-file

    while True:
        line = file_obj.readline()
        if not line:
            time.sleep(0.1)  # Sleep briefly
            continue

        yield line
    pass
