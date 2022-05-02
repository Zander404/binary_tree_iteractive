typedef struct NO* ArvBin;
ArvBin* cria_ArvBin();
//ArvBin* cria_ArvBinR();

void libera_NO(struct NO* no);
void libera_ArvBin(ArvBin* raiz);
int altura_ArvBin(ArvBin *raiz);
void preOrdem_ArvBin(ArvBin *raiz);
void emOrdem_ArvBin(ArvBin *raiz);
void posOrdem_ArvBin(ArvBin *raiz);
int insere_ArvBin(ArvBin * raiz, int valor);
int consulta_ArvBin(ArvBin * raiz, int valor);
int remove_ArvBin(ArvBin *raiz, int valor);
struct NO* remove_atual(struct NO* atual);
int totalNO_ArvBin(ArvBin *raiz);
struct NO* remove_NO_Iterativo(ArvBin * root, int key);

