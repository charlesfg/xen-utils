#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <xenctrl.h>


int main(int argc, char* argv[])
{
	int s32ret;
	int s32cmd;
	int s32domid;
	int s32vcpuid;
	if(4 != argc)
	{
		printf("Arg Err!\n");
		exit(EXIT_FAILURE);
	}

	s32cmd    = atoi(argv[1]);
	s32domid  = atoi(argv[2]);
	s32vcpuid = atoi(argv[3]);
	xc_interface *pxch;

	pxch = xc_interface_open(NULL, NULL, 0);
	s32ret = xc_rtds_boost(pxch, s32cmd, s32domid, s32vcpuid);
	xc_interface_close(pxch);

	printf("Ret = %d\n", s32ret);

	return 0;
}
