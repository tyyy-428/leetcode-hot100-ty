bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    //m��ʾ�м��У�n��ʾһ���������飬�洢��ÿһ�е�Ԫ�ظ�������Ϊÿһ����һ��һά���飬��������=Ԫ������
    int m = matrixSize, n = matrixColSize[0];
    //��ʾ�ϲ���������±꣨��Χ��
    int low = 0, high = m * n - 1;

    while (low <= high)
    {
        //mid��ѭ��������Ҫ��̬�����м�ֵ
        int mid = low + (high - low) / 2;

        int x = matrix[mid / n][mid % n];
        //��̬���������ޣ�һ�ο��Լ���һ��
        if (x < target)
            low = mid + 1;
        else if (x > target)
            high = mid - 1;
        else return true;
    }

    return false;
}