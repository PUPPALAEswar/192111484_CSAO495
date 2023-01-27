#include <stdio.h>
struct Employee {
	int id;
	char name[25];
	float salary;
};

void write_employee(FILE *fp, struct Employee emp) {
	fseek(fp, emp.id * sizeof(struct Employee), SEEK_SET);
	fwrite(&emp, sizeof(struct Employee), 1, fp);
}

struct Employee read_employee(FILE *fp, int id) {
	struct Employee emp;
	fseek(fp, id * sizeof(struct Employee), SEEK_SET);
	fread(&emp, sizeof(struct Employee), 1, fp);
	return emp;
}

int main() {
	FILE *fp = fopen("employee.dat", "w+b");
	if (fp == NULL) {
		printf("Error opening file\n");
		return 1;
	}
	struct Employee emp;
	printf("Enter employee ID: ");
	scanf("%d", &emp.id);
	printf("Enter employee name: ");
	scanf("%s", emp.name);
	printf("Enter employee salary: ");
	scanf("%f", &emp.salary);
	write_employee(fp, emp);
	struct Employee read_emp = read_employee(fp, emp.id);
	printf("ID: %d, Name: %s, Salary: %.2f\n", read_emp.id, read_emp.name, read_emp.salary);
	fclose(fp);
	return 0;
}
