#include <stdio.h>
#include <stdlib.h>
#include "library.h"
int main() {
    BookNode* bookList = NULL;
    BorrowerNode* borrowerList = NULL;
    int choice;

    // ���ļ���������
    loadBooksFromFile(&bookList);
    loadBorrowersFromFile(&borrowerList);

    while (1) {
        printf("ͼ����ͨ����ϵͳ\n");
        printf("1. �½�ͼ��\n");
        printf("2. ��ʾ����ͼ��\n");
        printf("3. �޸�ͼ����Ϣ\n");
        printf("4. ɾ��ͼ��\n");
        printf("5. ע�������\n");
        printf("6. ����\n");
        printf("7. ����\n");
        printf("8. �˳�\n");
        printf("��ѡ�����: ");
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
            // �������ݵ��ļ�
            saveBooksToFile(bookList);
            saveBorrowersToFile(borrowerList);
            printf("�˳�ϵͳ.\n");
            return 0;
        default:
            printf("��Ч������������ѡ��!\n");
        }
    }

    return 0;
}
