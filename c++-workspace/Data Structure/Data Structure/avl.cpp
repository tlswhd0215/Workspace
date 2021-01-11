#include <iostream>
#include <algorithm>
using namespace std;

class node {
public:
	int data;
	node* nleft;
	node* nright;
	node() {
		data = NULL;
		nleft = NULL;
		nright = NULL;
	}
};
class AVL {
public:
	node* root;
	int height(node*);			//노드의 높이 구하기
	int bal(node*);				//balanced인지 값 구하기
	node* RR(node*);			//RR로테이션
	node* LL(node*);			//LL로테이션
	node* RL(node*);			//RL로테이션
	node* LR(node*);			//LR로테이션
	node* rebalance(node*);		//균형 맞추기
	node* makeNode();			//새 노드 만들기
	int compare(int, node*);	//값 비교
	node* insert(node*,int);	//원소 삽입
	int remove(node*, int);		//원소 삭제
	node* search(node*, int);	//원소 탐색
	void display(node*, int);	//트리 내용 출력
	AVL(){
		root = NULL;
	}
};
int main() {
	AVL _AVL;
	int menu;
	int data;
	while (1) {
		cout << endl << "############################### 메뉴 선택 ###############################" << endl;
		cout << "1번 : 데이터 삽입 || 2번 : 데이터 검색 || 3번 : 데이터 삭제 " << endl;
		cout << "4번 : AVL트리 출력|| 0번 : 종료	|| 메뉴를 선택하시오 <- ";
		cin >> menu;
		switch (menu) {
		case 1:
			cout << "삽입할 데이터 입력 : ";
			cin >> data;
			_AVL.root=_AVL.insert(_AVL.root, data);
			_AVL.display(_AVL.root, 1);
			break;
		case 2:
			cout << "검색할 데이터 입력 : ";
			cin >> data;
			if (_AVL.search(_AVL.root, data)!=NULL)
				cout << "검색 성공" << endl;
			else
				cout << "검색 실패" << endl;
			break;
		case 3:
			cout << "삭제할 데이터 입력 : ";
			cin >> data;
			if (_AVL.remove(_AVL.root, data))
				cout << "삭제 성공" << endl;
			else
				cout << "삭제 실패"<<endl;
			_AVL.display(_AVL.root, 1);
			break;
		case 4:
			_AVL.display(_AVL.root, 1);
			break;
		case 0:
			return 0;
		}
	}
}
int AVL::height(node* t) {
	int h = 0;
	if (t != NULL) {
		int left = height(t->nleft);
		int right = height(t->nright);
		int h_max = max(left, right);
		h = h_max+1;
	}
	return h;
}
int AVL::bal(node* t) {
	int left = height(t->nleft);
	int right = height(t->nright);
	int _bal = left - right;
	return _bal;
}
node* AVL::RR(node* p) {
	node* temp;
	temp = p->nright;
	p->nright = temp->nleft;
	temp->nleft = p;
	return temp;
}
node* AVL::RL(node* p) {
	node* temp;
	temp = p->nright;
	p->nright = LL(temp);
	return RR(p);
}
node* AVL::LL(node* p) {
	node* temp;
	temp = p->nleft;
	p->nleft = temp->nright;
	temp->nright = p;
	return temp;
}
node* AVL::LR(node* p) {
	node* temp;
	temp = p->nleft;
	p->nleft = RR(temp);
	return LL(p);
}
node* AVL::rebalance(node* t) {
	if (t == NULL) {
		return NULL;
	}
	t->nleft = rebalance(t->nleft);
	t->nright = rebalance(t->nright);
	int _bal = bal(t);
	if (-1 <= _bal && _bal <= 1)
		return t;
	if (_bal > 1) {
		t = bal(t->nleft) > 0 ? LL(t) : LR(t);
		return t;
	}
	t = bal(t->nright) < 0 ? RR(t) : RL(t);
	return t;
}
node* AVL::makeNode() {
	node* temp = new node;
	temp->data = NULL;
	temp->nleft = NULL;
	temp->nright = NULL;
	return temp;
}
int AVL::compare(int d, node* c) {
	return d > c->data;
}
node* AVL::insert(node* r,int d) {
	if (search(r, d) != NULL)
		return r;
	node* n = new node;
	n->data = d;
	node* cur = r;
	node* par = NULL;

	while (cur != NULL) {
		par = cur;
		cur = compare(d, cur) ? cur->nright : cur->nleft;
	}
	
	if (par == NULL) {
		r = n;
		return r;
	}
	if (compare(d, par)) {
		par->nright = n;
		r = rebalance(r);
		return r;
	}
	par->nleft = n;
	r = rebalance(r);
	return r;
}
int AVL::remove(node* r, int d) {
	node* cur = r;
	node* ptemp = makeNode();
	node* p = ptemp;
	ptemp->nright = r;
	while (cur != NULL && cur->data != d) {
		p = cur;
		cur = compare(d,cur) ? cur->nright : cur->nleft;
	}
	if (cur == NULL)
		return 0;
	node* del = cur;
	
	if (del->nleft == NULL && del->nright == NULL) {
		if (p->nleft == del)
			p->nleft = NULL;
		else
			p->nright = NULL;
	}
	else if (del->nleft == NULL || del->nright == NULL) {
		node* child = del->nleft == NULL ? del->nright : del->nleft;
		if (p->nleft == del) {
			p->nleft = child;
		}
		else
			p->nright = child;
	}
	else {
		node* movechild = del->nright;
		node* parent = del;
		while (movechild->nleft != NULL) {
			parent = movechild;
			movechild = movechild->nleft;
		}
		int data = del->data;
		del->data = movechild->data;

		if (parent->nleft == movechild)
			parent->nleft = movechild->nright;
		else
			parent->nright = movechild->nright;

		del = movechild;
		del->data = data;
	}
	if (ptemp->nright != r)
		r = ptemp->nright;
	delete ptemp;
	delete del;
	rebalance(root);
	return 1;
}
node* AVL::search(node* r, int d) {
	node* cur = r;
	while (cur != NULL) {
		int data = cur->data;
		if (data == d)
			return cur;
		cur = compare(d, cur) ? cur->nright : cur->nleft;
	}
	return NULL;
}
void AVL::display(node* r,int l) {
	if (r == NULL)
		return;
	int i;
	if (r != NULL) {
		display(r->nright, l + 1);
		cout << endl;
		if (r == root) {
			cout << "Root -> ";
		}
		for (i = 0; i < l&&r != root; i++) {
			cout << "\t";
		}
		cout << r->data;
		display(r->nleft, l + 1);
	}
}
