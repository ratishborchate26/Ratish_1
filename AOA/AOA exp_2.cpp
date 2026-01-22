#include <stdio.h>

int main()
{
    int n,i,l=0,r,mid,key;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter elements in sorted order:\n");
    for(i=0;i<n;i++) 
	scanf("%d",&a[i]);
    printf("Enter element to search: ");
    scanf("%d",&key);
    r=n-1;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(a[mid]==key)
        {
            printf("Element found at position %d",mid+1);
            return 0;
        }
        else if(a[mid]<key)
            l=mid+1;
        else
            r=mid-1;
    }
    printf("Element not found");
}

