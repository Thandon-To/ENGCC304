#include<stdio.h>

int main() {
    int employeeID = 10;
    int workinghrs = 0;
    float Salary;

    printf("Input the Employees ID(Max. 10 chars): ");
    scanf("%d", &employeeID);
    printf("Input the working hrs: ");
    scanf("%d", &workinghrs);
    printf("Salary amount/hr:");
    scanf("%f", &Salary);
    printf("Employee ID: %d\n", employeeID);
    printf("Salary = U$ %.2f\n", Salary * workinghrs);
}