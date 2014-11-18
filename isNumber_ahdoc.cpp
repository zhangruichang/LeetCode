#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std ;
class Solution {
    private:
        char suf[1009] ;
    public:
        bool isNumber(const char *s) {
            if ( strlen(s) == 3 && s[0] == '0' && s[1] == 'x' && s[2] == '.' ) return false ;
            memset( suf , 0 , sizeof(suf) ) ;
            for ( int i = 0 , j = 0 ; i < strlen(s) ; i ++ )
                if ( j == 0 ) {
                    if ( '.' == s[i] || '-' == s[i] || '+' == s[i] || ('0' <= s[i] && s[i] <= '9') ) suf[j++] = s[i] ;
                    else if ( s[i] != ' ' ) return false ;
                } else if ( j != 0 ) {
                    suf[j++] = s[i] ;
                }
            while ( suf[strlen(suf)-1] == ' ' ) suf[strlen(suf)-1] = 0 ;
            double xx ;
            int yy ;
            sscanf(suf , "%lf%n" , &xx , &yy) ;
//            printf("xx=%.10lf  yy=%d\n" , xx , yy) ;
            if ( yy == strlen(suf) && ( ('0' <= suf[strlen(suf)-1] && suf[strlen(suf)-1] <= '9') || '.' == suf[strlen(suf)-1] ) ) return true ;
            else return false ;
        }
} F ;

int main() {
    char suf[1009] ;
    while (gets(suf)) cout << F.isNumber(suf) << "\n" ;
}