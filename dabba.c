/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* canSeePersonsCount(int* heights, int heightsSize, int* returnSize){
int i,j,k,count=0;
int maxh;
int* ar=(int*)malloc(sizeof(int)*heightsSize);
 *returnSize=heightsSize;
for(i=0;i<heightsSize;i++)
 {   
     if(i!=heightsSize-1)
       maxh=heights[i+1];
     for(j=i+1;j<heightsSize;j++)
     {
        
        if(heights[i]>heights[j])
        {
            if(maxh<=heights[j])
            {
                maxh=heights[j];
                count++;
            }
            else{
            continue;
            }
        }
        else
        {
        count++;
        maxh=heights[i+1];
        break;
        }
         
     }
      ar[i]=count;
         count=0;
 }
 return ar;
}
