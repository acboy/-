#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <cstdlib>
#include <cctype>
#include <time.h>
using namespace std;

struct node{
	int a,b;
	bool operator < (const node& B) const{
		return a<B.a||(a==B.a&&b<B.b);
	}
};

multiset<node>S;
multiset<node>::iterator it;

int main()
{
    //freopen("A.in","r",stdin);
	int T;
	scanf("%d",&T);
	for (int ca=1;ca<=T;ca++){
		if (ca>1) puts("");
		printf("Case #%d:\n",ca);

		int n,a,b;
		scanf("%d",&n);
		S.clear();

		for (int i=0;i<n;i++){
			scanf("%d%d",&a,&b);
			node pp=(node){a,b};
			it=S.lower_bound(pp);
			if (it==S.begin()||(--it)->b>b){
				S.insert(pp);
				it=S.upper_bound(pp);
				while (it!=S.end()&&it->b>=b) S.erase(it++);
			}
			printf("%d\n",S.size());
		}
	}

}
