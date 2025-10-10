#include <stdio.h>
#include <locale.h>
#include <locale.h>

void print_grouped_ll(long long x, char sep){
    if (x >= 1000) { 
        print_grouped_ll(x/1000, sep);
        printf("%c%03lld", sep, x%1000);
    } else {
        printf("%lld", x);
    }
}

int main(void){
    char employeeID[11];
    int workinghrs = 0;
    float Salary;

    setlocale(LC_ALL, "");                          // ใช้โลเคลของระบบ
    struct lconv *lc = localeconv();
    char sep = (lc && lc->thousands_sep && lc->thousands_sep[0])
               ? lc->thousands_sep[0] : ',';        // ใช้ตัวคั่นจากโลเคล (ว่างก็ใช้ ,)

    printf("Input the Employees ID(Max. 10 chars): "); scanf("%10s", employeeID);
    printf("Input the working hrs: ");               scanf("%d", &workinghrs);
    printf("Salary amount/hr:");                     scanf("%f", &Salary);

    double total = (double)Salary * (double)workinghrs;
    long long whole = (long long)total;
    int cents = (int)((total - whole)*100 + 0.5);    // ปัดเศษทศนิยม 2 ตำแหน่ง

    printf("Expected Output:\n");
    printf("Employee ID: %s\n", employeeID);
    printf("Salary = U$ ");
    print_grouped_ll(whole, sep);
    printf(".%02d\n", cents);
    return 0;
}
