#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

/* CHUONG TRINH QUAN LY SINH VIEN
  function: nhap, in, xoa, them, chen, xuat file
*/

struct sv
{
    char ten[20];
    char MSSV[10];
    float dtb;
};

struct NODE
{
    sv info;
    struct NODE* pNext;
};

struct LIST
{
    NODE* pHead;
    NODE* pTail;
};

NODE* CreateNode (sv x)
{
    NODE* p;
    p = new NODE;
    if(p== NULL)
    {
        exit(1);
    }
    p -> info = x;
    p -> pNext = NULL;
    return p;
}

void CreateList (LIST &L);
void nhap (sv &x);
void AddLast(LIST &L, NODE* p);
void nhapN (LIST &L);
void xuat (sv x);
void xuatN (LIST L);
void maxdtb (LIST L);
void thongkedtb (LIST L);
void timTen (LIST L);
void timMSSV (LIST L);
void xoa (LIST L);
void chen (LIST &L);
void xuatFile (LIST L,  char fileName1[]);
void menu();

int main()
{
    while(1)
    {
        menu();
        getch();
    }
}

/* hàm để tạo linked list đầu chưa có data*/
void CreateList (LIST &L)
{
    L.pHead = L.pTail = NULL;
}

/* nhan thong tin sinh vien gom ten, mssv, dtb
   x: kieu du lieu sinh vien
*/
void nhap (sv &x)
{
    printf("\nNhap ten: ");
    fflush(stdin);
    gets(x.ten);

    printf("\nNhap MSSV: ");
    fflush(stdin);
    gets(x.MSSV);

    printf("\nNhap diem trung binh: ");
    scanf("%f", x.dtb);
}

/* tao them mot thong tin sinh vien o cuoi
   p: con tro den node moi
   thêm p vao cuoi list và chuyển pTail tro sang p
*/
void AddLast(LIST &L, NODE* p)
{
    if(L.pHead == NULL)
    {
        L.pHead = L.pTail = p;
    }else
    {
        L.pTail -> pNext = p;
        L.pTail = p;
    }
}

/* nhap thong tin N sinh vien
   kt: char de biet user nhap du sinh vien hay chua
   x: kieu du lieu sinh vien
*/
void nhapN (LIST &L)
{
    sv x;
    char kt;
    printf("\nNhan phim bat ki de tiep tuc nhap.");
    printf("\nNhan 0 de dung nhap.");
    do
    {
        kt=getch();
        if(kt == '0')
        {
            break;
        }
        nhap (x);
        NODE *p=CreateNode(x);
        AddLast(L,p);
    } while (1);
}

/* in ra man hinh thong tin 1 sinh vien
*/
void xuat (sv x)
{
    printf("\n\t\t\t %s", x.ten);
    printf("\t\t %s", x.MSSV);
    printf("\t\t %f", x.dtb);
}

/* in ra man hinh thong tin N sinh vien
*/
void xuatN (LIST L)
{
    NODE* p;
    p = L.pHead;
    while(p != NULL)
    {
        printf("\t\t---------------------");
        xuat (p -> info);
        p = p -> pNext;
    }
}

 /* in ra man hinh sinh vien co dtb cao nhat
    dem: bien dang so nguyen de dem so sv co dtb cao nhat
    max: con tro chi den sv co dtb cao nhat
    p: con tro chi den sv
 */
void maxdtb (LIST L)
{
    NODE *p, *max;
    int dem;
    p = L.pHead;
    max = p;

    while (p != NULL)
    {
        if(p-> info.dtb > max-> info.dtb)
        {
            max = p;
            dem = 0;
        }

        if(p-> info.dtb == max-> info.dtb)
        {
            max = p;
            dem++;
        }
        printf("\nSinh vien co diem trung binh cao nhat la: \n");

        if(dem = 0)
        {
            xuat(max->info);
        }
        else
        {
            NODE* q = L.pHead;
            while( q != NULL)
            {
                 if(q-> info.dtb == max-> info.dtb)
                 {
                     xuat(q -> info);
                 }
                 q = q-> pNext;
            }
        }
    }
}

 /* in ra so sinh vien co dtb >=5
    dem: bien so nguyen chi so sv co dtb >=5
    p: con tro chi den sv
 */
void thongkedtb (LIST L)
{
    NODE* p;
    int dem = 0;
    p = L.pHead;

    while (p != NULL)
    {
        if (p -> info.dtb >= 5)
        {
            dem++;
        }
        p = p -> pNext;
    }

    if (dem == 0)
    {
        printf("\nKhong co sinh vien nao co diem trung bình >= 5.");
    }else
    {
        printf("\nCó %d sinh vien co diem trung binh >= 5", dem);
    }
}

/* tim sinh vien theo ten
   dem: so sv co ten can tim
   k: array de so sanh ten trong danh sach
   p: con tro chi den sv
*/
void timTen (LIST L)
{
    NODE* p;
    int dem = 0;
    char k[20];

    printf("\nNhap ten sinh vien can tim: ");
    fflush(stdin);
    gets(k);
    p = L.pHead;

    while (p != NULL)
    {
        if(strcmp(k, p-> info.ten)==0)
        {
            dem ++;
        }
        p = p -> pNext;
    }

    if(dem != 0)
    {
        printf("\nDa tim thay sinh vien!!");
        xuat(p -> info);
    } else
    {
        printf("\nKhong tim thay sinh vien nay");
    }
}

/* tim sinh vien theo ma so
   q: array chua ma so can tim de so sanh voi ma so trong danh sach
*/
void timMSSV (LIST L)
{
    NODE* p;
    char q[10];
    int dem = 0;

    printf("\nNhap MSSV can tim: ");
    fflush(stdin);
    gets(q);
    p = L.pHead;

    while (p != NULL)
    {
        if(strcmp(q, p-> info.MSSV)==0)
        {
            printf("\nDa tim thay sinh vien!!");
            xuat(p -> info);
            dem++;
        }
        p = p -> pNext;
    }

    if(dem == 0)
    {
        printf("\nKhong tim thay sinh vien nay");
    }
}

/* xoa thong tin sinh vien
*/
void xoa (LIST L)
{
    NODE *p, *q;
    char a[20];
    char b[10];
    p = L.pHead;

    printf("\nNhap thong tin sinh vien can xoa");
    printf("\nTen: ");
    fflush(stdin);
    gets(a);
    printf("\nMSSV: ");
    fflush(stdin);
    gets(b);

    while(p != NULL)
    {
        if(strcmp(a, p -> info.ten) == 0)
        {
            if(strcmp(b, p -> info.MSSV) == 0)
            {
                q = p;
                break;
            }
            p = p -> pNext;
        }
    }

    if(q!=NULL)
    {
        if(p!=NULL)
        {
            q -> pNext = p -> pNext;
            delete (p);
            if (p == L.pTail)
            {
                L.pTail = q;
            }
            delete (p);
        }
    }else
    {
        L.pHead = p -> pNext;
        delete(p);
        if(L.pHead == NULL)
        {
           L.pTail = NULL;
        }
    }
}

 /* chen them thong tin sinh vien
 */
void chen (LIST &L)
{
    NODE *p,*q,*min;
    p = L.pHead;
    sv temp;

    while (p != L.pTail)
    {
        min = p;
        q = p -> pNext;
        while (q != NULL)
        {
            if(q -> info.dtb < min -> info.dtb)
            {
                min = q;
            }
            q = q -> pNext;
        }

        temp = p -> info;
        p -> info = min -> info;
        min -> info = temp;
        p = p -> pNext;
    }
}
void menu()
{
    LIST L;
    NODE *p,*q,*moi;
    sv x;
    char choice1, choice2;
    CreateList(L);

    do
    {
        printf("\n\t\t\tMENU");

        printf("\n\t1. Nhap ds");
        printf("\n\t2. In ds");
        printf("\n\t3. Ds sv co dtb cao nhat");
        printf("\n\t4. Ds sv co dtb >=5");
        printf("\n\t5. Tim sv");
        printf("\n\t6. Xoa sv");
        printf("\n\t7. Sap xep ds");
        printf("\n\t8. Chen sv");
        printf("\n\tNhap 0 de thoat");

        choice1 = getch();
        switch(choice1)
        {
            case '1':
                {
                    nhapN(L);
                    break;
                }

            case '2':
                {
                    xuatN(L); break;
                }

            case '3':
                {
                    maxdtb(L);
                    break;
                }

            case '4':
                {
                    thongkedtb(L);
                    break;
                }

            case '5':
                {
                    printf("\n\t1. Tim sinh vien theo ten");
                    printf("\n\t2. Tim sinh vien theo ma so");
                    printf("\n\tNhan 0 de thoat");
                    choice2 = getch();

                    switch(choice2)
                    {
                        case '1':
                            {
                                timTen(L);
                                break;
                            }
                        case '2':
                            {
                                timMSSV(L);
                                break;
                            }
                        case '0': exit(1);
                        default: printf("\nNhap lai.");
                    }
                    break;
                }

            case '6':
                {
                    xoa(L);
                    printf("\nDs sau khi xoa: ");
                    xuatN(L);
                    break;
                }

            case '7':
                {
                    chen(L);
                    printf("\nDs sau khi sap xep: ");
                    xuatN(L);
                    break;
                }

            case '8':
                {
                    sv them;
                    printf("\nNhap thong tin sv can them: ");
                    nhap(them);

                    NODE *t = CreateNode(them);
                    AddLast(L, t);
                    chen(L);

                    printf("\nDs sau khi them :");
                    xuatN(L);
                    break;
                }

            case '0': exit(1);
            default: printf("\nNhap lai.");
        }
    } while (choice1 != '0');
}

/* ham xuat file
*/
void xuatFile (LIST L,  char fileName1[])
{
    FILE * fp;
    NODE* p;
    p = L.pHead;
    fp = fopen (fileName1,"w");
    while( p != NULL)
    {
    fprintf(fp, "%20s%5s%10s\n", "Ho Ten","MSSV", "DTB");
    fprintf(fp, "%20s%5s%10s\n", p -> info.ten, p -> info.MSSV, p -> info.dtb);
    p = p -> pNext;
    }
}
