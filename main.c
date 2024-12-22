#include <stdio.h>
#include <stdlib.h>
#include "library.h"
int main() {
    BookNode* bookList = NULL;
    BorrowerNode* borrowerList = NULL;
    int choice;

    // 从文件加载数据
    loadBooksFromFile(&bookList);
    loadBorrowersFromFile(&borrowerList);

    while (1) {
        printf("图书流通管理系统\n");
        printf("1. 新进图书\n");
        printf("2. 显示所有图书\n");
        printf("3. 修改图书信息\n");
        printf("4. 删除图书\n");
        printf("5. 注册借书人\n");
        printf("6. 借书\n");
        printf("7. 还书\n");
        printf("8. 退出\n");
        printf("请选择操作: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addBook(&bookList);
            break;
        case 2:
            displayBooks(bookList);
            break;
        case 3:
            modifyBook(bookList);
            break;
        case 4:
            deleteBook(&bookList);
            break;
        case 5:
            registerBorrower(&borrowerList);
            break;
        case 6:
            borrowBook(bookList, borrowerList);
            break;
        case 7:
            returnBook(bookList, borrowerList);
            break;
        case 8:
            // 保存数据到文件
            saveBooksToFile(bookList);
            saveBorrowersToFile(borrowerList);
            printf("退出系统.\n");
            return 0;
        default:
            printf("无效操作，请重新选择!\n");
        }
    }

    return 0;
}
