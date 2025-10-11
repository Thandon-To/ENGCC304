#include <stdio.h>

int file(char *filename) {

    FILE *fp = fopen(filename, "r");  // ให้ fp ชี้ไปยังสตรีมไฟล์ที่เปิดได้

    int count = 0;
    char token[256];

    while (fscanf(fp, "%s", token) == 1) {  // อ่านคำทีละคำ (กันล้น)
        count++;
    } //end while

    fclose(fp);  // ปิดไฟล์เมื่ออ่านเสร็จ
    return count;
} //end function

int main() {
    char fname[256];

    printf("Enter file name:\n");
    scanf("%s", fname);

    int total = file(fname);

    printf("Total number of words in '%s' : %d words\n", fname, total);
    return 0;
}//end function
