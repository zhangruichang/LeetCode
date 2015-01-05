int GetOrder(int** pArr, int n, int m, int v);

int FindKth(int** pArr, int n, int m, int k)
{
        assert(pArr && m>0 && n>0 && k>0 && k<m*n);

        int nBeg = pArr[0][0];
        int nEnd = pArr[n-1][m-1];
        int nK = 0;
        int nMid = 0;
        
        int nPrev = -1;
        do
        {
                nMid = (nBeg + nEnd)/2;
                nK = GetOrder(pArr, m, n, nMid);
                if (nK == nPrev) break;
                nPrev = nK;

                if (nK < k)
                        nBeg = nMid;
                else
                        nEnd = nMid;
        }
        while(nK != k);

        int iCur = 0;
        int jCur = m-1;
        int nRet = 0;
        bool bFirst = true;
        while (iCur < n && jCur >= 0)
        {
                if (nMid > pArr[iCur][jCur])
                {
                        if (bFirst)
                        {
                                nRet = pArr[iCur][jCur];
                                bFirst = false;
                        }
                        else
                                nRet = nRet > pArr[iCur][jCur] ? nRet : pArr[iCur][jCur];

                        iCur++;
                }
                else
                {
                        jCur--;
                }
        }

        assert(!bFirst);

        return nRet;
}

int GetOrder(int** pArr, int m, int n, int v)
{
        assert(pArr && m>0 && n>0);

        int iCur = 0;
        int jCur = m-1;

        int nBiggerThan = 0;
        while (iCur < n && jCur >= 0)
        {
                if (pArr[iCur][jCur] >= v)
                {
                        nBiggerThan += n-iCur;
                        jCur--;
                }
                else iCur++;
        }

        return m*n - nBiggerThan;
}