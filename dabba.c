int* canSeePersonsCount(int* heights, int heightsSize, int* returnSize){
int i,j,k,count=0;
int* ar=(int*)malloc(sizeof(int)*heightsSize);
int maxh=heights[1];
 *returnSize=heightsSize;
for(i=0;i<heightsSize;i++)
 {
     for(j=i+1;j<heightsSize;j++)
     {
        if(heights[i]>heights[j])
        {
            if(maxh<heights[j])
            {
                maxh=heights[j];
                count++;
            }
            else
             count++;
        }
        else
        {
        count++;
        break;
        }
         
     }
      ar[i]=count;
         count=0;
 }
 return ar;
}
