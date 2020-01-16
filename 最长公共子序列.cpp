int **Lcs_length(string X,string Y,int **B)
{
	int x_len = X.length();
	int y_len = Y.length();
 
	int **C = new int *[x_len+1];
	for (int i = 0; i <= x_len; i++)
	{
		C[i] = new int[y_len + 1];        //定义一个存放最优解的值的表；
	}
 
	for (int i = 1; i <= x_len; i++)
	{
		C[i][0] = 0;
		B[i][0] = -2;                     //-2表示没有方向
	}
 
 
	for (int j = 0; j <= y_len; j++)
	{
		C[0][j] = 0;
		B[0][j] = -2;
	}
	
	for (int i = 1; i <= x_len; i++)
	{
		for (int j = 1; j <= y_len; j++)
		{
 
			if (X[i-1]==Y[j-1])
			{
				C[i][j] = C[i - 1][j - 1] + 1;
 
				B[i][j] = 0;             //0表示斜向左上
			}
			else
			{
				if (C[i-1][j]>=C[i][j-1])
				{
					C[i][j] = C[i - 1][j];
					B[i][j] = -1;       //-1表示竖直向上；
				}
				else
				{
					C[i][j] = C[i][j - 1];
					B[i][j] = 1;        //1表示横向左
				}
			}
 
		}
	}
	return C;