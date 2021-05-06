#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

typedef struct bankNode BankNode;
typedef struct bankNode *PtrBankNode;

typedef struct currFromNode CurrFromNode;
typedef struct currFromNode *PtrCurrFromNode;

typedef struct currToNode CurrToNode;
typedef struct currToNode *PtrCurrToNode;

typedef struct List List;
typedef struct List *PtrList;

struct bankNode
{
    char bankname[20];
    int currno;
    PtrBankNode next;
    PtrCurrFromNode Currhead;
};

struct currFromNode
{
    char currname[20];
    PtrCurrFromNode next;
    PtrCurrToNode FirstCurrTo;
};

struct currToNode
{
    char currname[20];
    float currconv;
    PtrCurrToNode next;
};

struct List
{
    int index;
    int currconv;
    PtrList next;
};

PtrBankNode InitBankNode();
PtrBankNode findBank(PtrBankNode BankHead, char bankname[]);

PtrCurrFromNode InitCurrFromNode();
PtrCurrFromNode findCurrFromNode(PtrCurrFromNode TrvCurrFrom, char currname[]);
PtrCurrFromNode addCurrFromNode(PtrCurrFromNode CurrHead, char currname[]);

PtrCurrToNode InitCurrToNode();
PtrCurrToNode findCurrToNode(PtrCurrFromNode TrvCurrFrom, char currname[]);

PtrList InitListNode();

bool BankDoesntExist(PtrBankNode BankHead, char bankname[],int mode);
bool NoBanksExist(PtrBankNode BankHead,int mode);
bool CurrencyAlreadyPresent(PtrCurrFromNode TrvCurrFrom, char currname[],int mode);
bool NoCurrencyExists(PtrBankNode BankHead, char bankname[],int mode);

void addBank(PtrBankNode BankHead, char bankname[]);
void printBanks(PtrBankNode BankHead);
void addCurrToNode(PtrCurrFromNode TrvCurrFrom, char currname[]);
void addCurr(PtrBankNode BankHead, char bankname[], char currname[]);
void printAllCurr(PtrBankNode BankHead,char bankname[]);
void delCurr(PtrBankNode BankHead, char currname[],char bankname[],int mode);
void findLoc(PtrCurrFromNode P, char currfrom[],char currto[],float currconv);
void addConv(PtrBankNode BankHead,char currfrom[],char currto[],float currconv, char bankname[], int mode);
void delBank(PtrBankNode BankHead,char bankname[]);
void getList(PtrBankNode BankHead,char bankname[]);

int getConv(PtrCurrFromNode P, char currfrom[],char currto[]);



