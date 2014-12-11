int Read4096(char* buf);
//read 4096 bytes from cur point of a file, if no more than 4096 remain, I will read the remain bytes, if nothing, return 0;

int Read(char* buf, int n)
{
    char buffer[4097];
    int ttcnt=0;
    bool eof=0;
    while(!eof && ttcnt<n)
    {
        int curcnt=Read4096(buffer);
        if(curcnt < 4096) eof=1;//end of file, in case that file num < n
        int movebytes=min(n-ttcnt, curcnt);//min means that read bytes > remain need copy bytes, 
        memcpy(buf+ttcnt, buffer, movebytes);
        ttcnt+=movebytes;
    }
    return ttcnt;
}

class Read
{
private:
    char buffer[4097];
    int offset=0;
    int buffersize=0;
public: 
    int ReadMultiple(char* buf, int n)
    {
        int ttcnt=0;
        bool eof=0;
        while(!eof && ttcnt<n)
        {
            if(buffersize==0)
            {
                tmp=Read4096(buffer);
                eof= tmp<4096 ;
            }
            int bytes=min(n-ttcnt, tmp);
            memcpy(buf+ttcnt, buffer+offset, bytes);
            offset=(offset+bytes)%4096;
            buffersize-=bytes;
            ttcnt+=bytes;   
        }
        return ttcnt;
    }
};

public class Solution extends Reader4 { 
   private char[] buffer = new char[4]; 
   int offset = 0, bufsize = 0; 
   /** 
    * @param buf Destination buffer 
    * @param n   Maximum number of characters to read 
    * @return    The number of characters read 
    */ 
   public int read(char[] buf, int n) { 
      int readBytes = 0; 
      boolean eof = false; 
      while (!eof && readBytes < n) { 
         if (bufsize == 0) { 
            bufsize = read4(buffer); 
            eof = bufsize < 4; 
         } 
         int bytes = Math.min(n - readBytes, bufsize); 
         System.arraycopy(buffer /* src */, offset /* srcPos */, 
               buf /* dest */, readBytes /* destPos */, bytes /* length */); 
         offset = (offset + bytes) % 4; 
         bufsize -= bytes; 
         readBytes += bytes; 
      } 
      return readBytes; 
   } 
} 