
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
void fn() {
/*
   ifstream fstr;
   int lines,v_count = 0,e_count = 0,a,b;
   string line;
   fstr.open("graph.txt");
   while (std::getline(fstr,line)) {
      fstr >> a ;
      fstr >> b;
      cout << a << " " << b << endl;
      if (a > v_count) {
         v_count = a;
      } else if (b > v_count) {
         v_count = b;
      }
      e_count++;
   }

   fstr.close();
*/
}

 
using namespace std;
 
int main() {
        FILE *fp;
        fp = fopen("gdata", "r");
	
		while ( !feof(fp))
		{
			int x,y;
                        fscanf(fp, "%d %d",&x, &y);
                        printf("%d %d\n", x,y);
                        
		}
        fclose(fp);

}
