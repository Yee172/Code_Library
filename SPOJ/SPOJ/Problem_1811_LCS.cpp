#include <bits/stdc++.h>

#pragma optimize("Ofast")
using namespace std;

#ifdef Yee_172
#include "template/tools/local_test.hpp"
#else
#define _______ ;
#define _debug(...) ;
#endif

typedef long long ll;
#define rep(i, n) for (int (i) = 0; (i) < (n); ++(i))
#define _rep(i, n) for (int (i) = 1; (i) <= (n); ++(i))

namespace suffix_automaton
{
    const int MAXN = 250050;
    const int MAXM = 26;
    int SAM_size = 0;

    char s[MAXN];
    int length_s = 0;

    class __node
    {
    public:
        __node * _father, * _next[MAXM];
        int length;
        int id;
        int position;
        __node(){};
        explicit __node(int length) : _father(0), length(length), id(SAM_size), position(0)
        { memset(_next, 0, sizeof _next); }
    };

    __node SAM_node[MAXN << 1], *SAM_root, *SAM_last;

    inline __node * new_node(int length)
    {
        SAM_node[SAM_size] = __node(length);
        return &SAM_node[SAM_size++];
    }
    inline __node * new_node(__node *p)
    {
        SAM_node[SAM_size] = *p;
        SAM_node[SAM_size].id = SAM_size;
        return &SAM_node[SAM_size++];
    }

    inline void initialize()
    {
        SAM_size = 0;
        SAM_root = SAM_last = new_node(0);
        SAM_node[0].position = 0;
    }

    inline void add_node(int x, int length)
    {
        __node *p = SAM_last, *np = new_node(p->length + 1);
        np->position = length;
        SAM_last = np;
        for (; p && !p->_next[x]; p = p->_father) p->_next[x] = np;
        if (!p)
        {
            np->_father = SAM_root;
            return;
        }
        __node *q = p->_next[x];
        if (q->length == p->length + 1)
        {
            np->_father = q;
            return;
        }
        __node *nq = new_node(q);
        nq->length = p->length + 1;
        q->_father = nq;
        np->_father = nq;
        for (; p && p->_next[x] == q; p = p->_father) p->_next[x] = nq;
    }
}
using namespace suffix_automaton;
char t[MAXN];
int length_t;
int res, res_tmp;
__node * tmp;

inline void get_max(int &a, const int &b) { a = a > b ? a : b; }

inline void construct()
{
    int i = 0;
    initialize();
    while (i < length_s) add_node(s[i] - 'a', ++i);
}

inline void match()
{
    int next_index;
    res = 0;
    res_tmp = 0;
    tmp = SAM_root;
    rep(i, length_t)
    {
        next_index = t[i] - 'a';
        if (tmp->_next[next_index])
        {
            tmp = tmp->_next[next_index];
            ++res_tmp;
        }
        else
        {
            while (tmp && !tmp->_next[next_index]) tmp = tmp->_father;
            if (!tmp) tmp = SAM_root, res_tmp = 0;
            else
            {
                res_tmp = tmp->length + 1;
                tmp = tmp->_next[next_index];
            }
        }
        get_max(res, res_tmp);
    }
}

int main()
{
    while (~scanf("%s%s", s, t))
    {
        length_s = (int) strlen(s);
        length_t = (int) strlen(t);
        construct();
        match();
        printf("%d\n", res);
    }
    return 0;
}
