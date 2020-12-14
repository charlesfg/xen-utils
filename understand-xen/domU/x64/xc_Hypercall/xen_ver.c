#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <xenctrl.h>


int main(int argc, char* argv[])
{
	long s64xenver = 0;
	xc_interface *pxch;

	pxch = xc_interface_open(NULL, NULL, 0);
	s64xenver = xc_version(pxch, XENVER_version, NULL);
	xc_interface_close(pxch);

	printf("Xen version %ld.%ld\n", s64xenver >> 16, s64xenver & 0xffff);

	return 0;
}
