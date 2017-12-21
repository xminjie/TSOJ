#include<stdio.h>
#include<stdlib.h>

typedef struct Node *PtrToNode;
struct Node {
	int Score;
	int Num;
	PtrToNode Next;
};
typedef PtrToNode List;

List CreatList(int);

int main() {
	freopen("test.txt","r",stdin); 
	int N, score;
	while(scanf("%d", &N) != EOF) {
		List L = CreatList(0);
		List P;
		for(int i = 0; i < N; i++) {
			P = L;
			scanf("%d", &score);

			while(P) {

				if(P->Next == NULL) {
					P->Next = CreatList(score);
					P = P->Next;
					break;
				} else if(score > P->Next->Score) {
					P = P->Next;
				} else if(score == P->Next->Score) {
					P->Next->Num++;
					break;
				} else if(score < P->Next->Score) {
					List Q = CreatList(score);
					Q->Next = P->Next;
					P->Next = Q;
					break;
				}
			}
		}
		List Q;
		Q = L;
		P = L->Next;
		free(Q);
		while(P) {
			printf("%d %d\n", P->Score, P->Num);
			Q = P;
			P = P->Next;
			free(Q);
		}

	}

}

List CreatList(int score) {
	List L = (List)malloc(sizeof(struct Node));
	L->Next = NULL;
	L->Score = score;
	L->Num = 1;
	return L;
}
