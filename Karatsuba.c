#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#define MAX 32001
#define max(x,y) ((x>y)?x:y)
char M1[MAX];
char M2[MAX];
char res[2*MAX];
void add_zeros(char* a, int n)
{
  int lena = strlen(a);
  for (int i = lena - 1 + n; i >= n; --i)
  {
    a[i] = a[i - n];
  }
  a[lena + n] = 0;
  for (int i = 0; i < n; ++i)
  {
    a[i] = '0';
  }
}
 
void remove_zeros(char* a)
{
  int lena = strlen(a);
  int ind = 0;
  while (ind < lena && a[ind] == '0')
  {
    ++ind;
  }
  for (int i = ind; i < lena; ++i)
  {
    a[i - ind] = a[i];
  }
  a[lena - ind] = 0;
}
 
void swap(char** ptr1,char** ptr2)
{
    char* temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}
 
void sum(char* a, char* b, char* res)
{
  int lena = strlen(a);
  int lenb = strlen(b);
 
 if (lena < lenb)
  {
    swap(&a, &b);
    int temp=lena;
    lena=lenb;
    lenb=temp;
  }
 
  int toAdd = 0;
  for (int inda = lena - 1, indb = lenb - 1; inda >= 0; --inda, --indb)
    {
        int x = a[inda] - '0';
        int y = indb >= 0 ? b[indb] - '0' : 0;
 
        int cur = x + y + toAdd;
 
        if (cur >= 10)
        {
          toAdd = 1;
          cur -= 10;
        }
        else
        {
          toAdd = 0;
        }
 
        res[inda] = cur + '0';
    }
 
  if (toAdd == 1)
  {
    add_zeros(res, 1);
    res[0] = '1';
  }
}
 
// assume that a > b
void sub(char* a, char* b, char* res)
{
  int lena = strlen(a);
  int lenb = strlen(b);
 
  //assert(lena >= lenb);
 
  int toSub = 0;
  for (int inda = lena - 1, indb = lenb - 1; inda >= 0; --inda, --indb)
  {
    int x = a[inda] - '0';
    int y = indb >= 0 ? b[indb] - '0' : 0;
 
    if (toSub == 1)
    {
      x--;
    }
    int cur;
    if (x < y)
    {
      cur = x + 10 - y;
      toSub = 1;
    }
   else
   {
      cur = x - y;
      toSub = 0;
   }
 
    res[inda] = cur + '0';
  }
}
 
// returns a * 10^n
void mult10(char* a, int n)
{
  int lena = strlen(a);
  if (lena == 1 && a[0] == '0')
  {
    return;
  }
  for (int i = lena; i < lena + n; ++i)
  {
    a[i] = '0';
  }
  a[lena + n] = 0;
}
 
char* CreateArray(int len)
{
  char* res = (char*)malloc(len*sizeof(char*));
  memset(res, 0, len);
  return res;
}
 
// add leading zeros if needed
void make_equal_length(char* a, char* b)
{
  int lena = strlen(a);
  int lenb = strlen(b);
  int n = max(lena, lenb);
  add_zeros(a, n - lena);
  add_zeros(b, n - lenb);
}
 
void karatsuba(char* x, char* y, char* res)
{
  make_equal_length(x, y);
  int len = strlen(x);
  if (len == 1)
    {
    int val = (x[0] - '0') * (y[0] - '0');
    if (val < 10) {
      res[0] = val + '0';
    }
  else
    {
      res[0] = (val / 10) + '0';
      res[1] = (val % 10) + '0';
    }
  }
  else
  {
    char* xl = CreateArray(len);
    char* xr = CreateArray(len);
    char* yl = CreateArray(len);
    char* yr = CreateArray(len);
 
    int rightSize = len / 2;
    int leftSize = len - rightSize;
 
    strncpy(xl, x, leftSize);
    strcpy(xr, x + leftSize);
    strncpy(yl, y, leftSize);
    strcpy(yr, y + leftSize);
    int maxl = 3 * len;
    char* P1 = CreateArray(maxl);
    char* P2 = CreateArray(maxl);
    char* P3 = CreateArray(maxl);
 
    karatsuba(xl, yl, P1);
    karatsuba(xr, yr, P2);
    char* tmp1 = CreateArray(maxl);
    char* tmp2 = CreateArray(maxl);
    sum(xl, xr, tmp1);
    sum(yl, yr, tmp2);
    karatsuba(tmp1, tmp2, P3);
    sub(P3, P1, P3);
    sub(P3, P2, P3);
    mult10(P3, rightSize);
    mult10(P1, 2 * rightSize);
    sum(P1, P2, res);
    sum(res, P3, res);
    remove_zeros(res);
 
    free(xl);
    free(xr);
    free(yl);
    free(yr);
    free(tmp1);
    free(tmp2);
    free(P1);
    free(P2);
    free(P3);
  }
}
 
int main(void) {
	int t;
	scanf("%d", &t);
	for(int t_c = 1; t_c<=t; t_c++)
	{
	   
	    scanf("%s %s", M1, M2);
	    karatsuba(M1,M2,res);
	    printf("#%d ",t_c);
	    printf("%s \n",res);
	}
	
	return 0;
}