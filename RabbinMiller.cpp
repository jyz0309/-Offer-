
bool RabbinMillerTest( unsigned n )
{
    if (n<2)
    {
        // 小于2的数即不是合数也不是素数  
        throw 0;
    }
    const unsigned nPrimeListSize=sizeof(g_aPrimeList)/sizeof(unsigned);//求素数表元素个数  
    for(int i=0;i<nPrimeListSize;++i)
    {
        // 按照素数表中的数对当前素数进行判断  
        if (n/2+1<=g_aPrimeList[i])
        {
            // 如果已经小于当前素数表的数，则一定是素数  
            return true;
        }
        if (0==n%g_aPrimeList[i])
        {
            // 余数为0则说明一定不是素数  
            return false;
        }
    }
    // 找到r和m，使得n = 2^r * m + 1;  
    int r = 0, m = n - 1; // ( n - 1 ) 一定是合数  
    while ( 0 == ( m & 1 ) )
    {
        m >>= 1; // 右移一位  
        r++; // 统计右移的次数  
    }
    const unsigned nTestCnt = 8; // 表示进行测试的次数  
    for ( unsigned i = 0; i < nTestCnt; ++i )
    {
        // 利用随机数进行测试，  
        int a = g_aPrimeList[ rand() % nPrimeListSize ];
        if ( 1 != Montgomery( a, m, n ) )
        {
            int j = 0;
            int e = 1;
            for ( ; j < r; ++j )
            {
                if ( n - 1 == Montgomery( a, m * e, n ) )
                {
                    break;
                }
                e <<= 1;
            }
            if (j == r)
            {
                return false;
            }
        }
    }
    return true;  
