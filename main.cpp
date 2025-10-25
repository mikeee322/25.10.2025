#include <iostream>

bool isPyth(unsigned a, unsigned b, unsigned c);

bool isMax(unsigned a, unsigned b, unsigned c){
  bool m = a > a*a + b*b;
  m = m || b > a*a + b*b;
  m = m || a > a*a + c*c;
  m = m || c > a*a + c*c;
  m = m || b > b*b + c*c;
  m = m || c > b*b + c*c;
  return m;
}

int main(){
  using u_t = unsigned;
  u_t a = 0, b = 0, c = 0;
  size_t count = 0;
  std::cin >> b >> c;
  while (std::cin>>a){
    count+=isPyth(a, b, c) ? 1 : 0;
    c=b;
    b=a;
  }
  if(std::cin.eof() && isMax){
    std::cerr << "crossing the limit\n";
    return 2;
  }
  if(std::cin.eof()){
    std::cout << count;
    std::cout << "\n";
  }
  else if (std::cin.fail()){
    std::cerr << "input err\n";
    return 1;
  }
}

bool isPyth (unsigned a, unsigned b, unsigned c){
  bool p = a*a==(b*b+c*c);
  p = p||b*b==(a*a+c*c);
  p = p||c*c==(a*a+b*b);
  return p;
}
