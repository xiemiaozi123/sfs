GetWater(m,S[num],L)
let B[] be a array ,and B[0]=0;
j=0;
for i= 0~num-1;
    if(S[i]-B[j]>m)
j++;
       B[j] = S[i-1];
if (L-S[]<=m)
   B[++j] = S[i];
return B[]