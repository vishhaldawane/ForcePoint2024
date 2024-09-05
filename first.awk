#!/usr/bin/awk -f

BEGIN {
	FS="|"
	printf("\n\n --- EMPLOYEE INFORMATION --- \n\n");
}

{
	printf("\nEMPLOYEE RECORD  : %d",NR);
	printf("\nEMPLOYEE NUMBER  : %d",$1);
	printf("\nEMPLOYEE NAME    : %s",$2);
	printf("\nEMPLOYEE DESG    : %s",$3);
	printf("\nEMPLOYEE DEPT    : %s",$4);
	printf("\nEMPLOYEE JOINING : %s",$5);
	printf("\nEMPLOYEE SALARY  : %12.2f",$6);
	printf("\n--------------------------------");
}

END {
	
	printf("\n\n --- EMPLOYEE COUNT : %d--- \n\n",NR);
}
