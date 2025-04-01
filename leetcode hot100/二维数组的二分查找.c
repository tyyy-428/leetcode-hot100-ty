bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    //m表示有几行，n表示一个整型数组，存储着每一行的元素个数（因为每一行是一个一维数组，所以列数=元素数）
    int m = matrixSize, n = matrixColSize[0];
    //表示合并后数组的下标（范围）
    int low = 0, high = m * n - 1;

    while (low <= high)
    {
        //mid在循环里是需要动态调整中间值
        int mid = low + (high - low) / 2;

        int x = matrix[mid / n][mid % n];
        //动态调整上下限，一次可以减少一半
        if (x < target)
            low = mid + 1;
        else if (x > target)
            high = mid - 1;
        else return true;
    }

    return false;
}