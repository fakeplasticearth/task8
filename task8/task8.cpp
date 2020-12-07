#include <iostream>
#include <vector>
using namespace std;

struct monomial{
    int degree;
    float coef;
    monomial(){}
    monomial(float c, int d): coef(c), degree(d){}
};

monomial x(1, 1);

struct polynomial{
    monomial curr;
    struct polynomial* next;
};

monomial operator * (float& num, monomial& m) {
    return monomial(m.coef * num, m.degree);
}

monomial operator * (monomial& left, monomial& right) {
    return monomial(left.coef * right.coef, left.degree + right.degree);
}

bool operator == (polynomial& p1, polynomial& p2) {
    bool ans = 1;
    polynomial* ptr1 = &p1;
    polynomial* ptr2 = &p2;
    while (ptr1 != NULL) {
        if ((*ptr1).curr.coef != (*ptr2).curr.coef || (*ptr1).curr.degree != (*ptr2).curr.degree) {
            ans = 0;
            break;
        }
        ptr1 = (*ptr1).next;
        ptr2 = (*ptr2).next;
    }
    if (ptr2 != NULL)
        ans = 0;
    return ans;
}

polynomial operator * (float& num, polynomial& p) {
    polynomial ans;
    polynomial* ans_curr = &ans;
    polynomial* ptr = &p;
    while (ptr != NULL) {
        (*ans_curr).curr = monomial(num * (*ptr).curr.coef, (*ptr).curr.degree);
        if ((*ptr).next != NULL)
            (*ans_curr).next = new polynomial;
        else
            (*ans_curr).next = NULL;
        ptr = (*ptr).next;
        ans_curr = (*ans_curr).next;
    }
    return ans;
}

polynomial operator * (monomial& m, polynomial& p) {
    polynomial ans;
    polynomial* ptr = &p;
    polynomial* ans_curr = &ans;
    while (ptr != NULL) {
        (*ans_curr).curr = monomial(m.coef * (*ptr).curr.coef, (*ptr).curr.degree + m.degree);
        if ((*ptr).next != NULL)
            (*ans_curr).next = new polynomial;
        else
            (*ans_curr).next = NULL;
        ans_curr = (*ans_curr).next;
        ptr = (*ptr).next;
    }
    return ans;
}

polynomial operator + (monomial& m, polynomial& p) {
    polynomial* ans = new polynomial;
    (*ans).curr = m;
    polynomial* ptr = &p;
    polynomial* ans_curr = ans;
    (*ans_curr).next = NULL;
    bool f1 = 0, f2 = 0;
    while (ptr != NULL) {
        if (f1) {
            polynomial* tmp = new polynomial;
            (*tmp).curr = (*ptr).curr;
            (*tmp).next = NULL;
            (*ans_curr).next = tmp;
            ans_curr = tmp;
        }
        else {
            if ((*ptr).curr.degree > m.degree) {
                if (!f2) {
                    polynomial* tmp = new polynomial;
                    (*tmp).curr = (*ptr).curr;
                    (*tmp).next = ans_curr;
                    ans = tmp;
                    f2 = 1;
                }
                else {
                    polynomial* tmp = new polynomial;
                    (*tmp).curr = (*ans_curr).curr;
                    (*tmp).next = NULL;
                    (*ans_curr).curr = (*ptr).curr;
                    (*ans_curr).next = tmp;
                    ans_curr = tmp;
                }
            }
            else if ((*ptr).curr.degree == m.degree) {
                if (!f2)
                    f2 = 1;
                (*ans_curr).curr = monomial(m.coef + (*ptr).curr.coef, m.degree);
                f1 = 1;
            }
            else {
                f1 = 1;
                continue;
            }
        }
        ptr = (*ptr).next;
    }
    return (*ans);
}

polynomial operator + (polynomial& p1, polynomial& p2) {
    polynomial* ptr = &p1;
    polynomial ans = p2;
    while (ptr != NULL) {
        ans = (*ptr).curr + ans;
        ptr = (*ptr).next;
    }
    return ans;
}

polynomial lukas_p(int k) {
    if (k == 0) {
        polynomial p;
        p.curr = monomial(2, 0);
        p.next = NULL;
        return p;
    }
    if (k == 1) {
        polynomial p;
        p.curr = monomial(1, 1);
        p.next = NULL;
        return p;
    }
    polynomial left = lukas_p(k - 1), right = lukas_p(k - 2);
    left = x * left;
    return left + right;
}

int main()
{
    //10 многочленов в массиве
    vector <polynomial> vec(10);
    vector <polynomial>::iterator it = vec.begin();
    polynomial p1, p2;
    p1.curr = monomial(2, 0);
    p1.next = NULL;
    p2.curr = monomial(1, 1);
    p2.next = NULL;
    *(it) = p1;
    *(it + 1) = p2;
    for (int i = 2; i < 10; i++) {
        polynomial left = x * (*(it + i - 1));
        polynomial right = *(it + i - 2);
        *(it + i) = left + right;
    }

    it = vec.begin();
    for (int i = 0; i < 10; i++) {
        polynomial* ptr = &(*(it + i));
        bool first = 1;
        while (ptr != NULL) {
            if (first) {
                if ((*ptr).curr.coef != 1)
                    cout << (*ptr).curr.coef;
                if ((*ptr).curr.degree != 0) {
                    if ((*ptr).curr.degree == 1)
                        cout << "x";
                    else
                        cout << "x^(" << (*ptr).curr.degree << ')';
                }
                first = 0;
            }
            else {
                if ((*ptr).curr.coef > 0)
                    cout << " + ";
                else
                    cout << " - ";
                if ((*ptr).curr.coef != 1)
                    cout << (*ptr).curr.coef;
                if ((*ptr).curr.degree != 0) {
                    if ((*ptr).curr.degree == 1)
                        cout << "x";
                    else
                        cout << "x^(" << (*ptr).curr.degree << ')';
                }
            }
            ptr = (*ptr).next;
        }
        cout << '\n';
    }
    int n;
    cin >> n;
    bool first = 1;
    polynomial tmp = lukas_p(n);
    polynomial* ptr = &tmp;
    while (ptr != NULL) {
        if (first) {
            if ((*ptr).curr.coef != 1)
                cout << (*ptr).curr.coef;
            if ((*ptr).curr.degree != 0) {
                if ((*ptr).curr.degree == 1)
                    cout << "x";
                else
                    cout << "x^(" << (*ptr).curr.degree << ')';
            }
            first = 0;
        }
        else {
            if ((*ptr).curr.coef > 0)
                cout << " + ";
            else
                cout << " - ";
            if ((*ptr).curr.coef != 1)
                cout << (*ptr).curr.coef;
            if ((*ptr).curr.degree != 0) {
                if ((*ptr).curr.degree == 1)
                    cout << "x";
                else
                    cout << "x^(" << (*ptr).curr.degree << ')';
            }
        }
        ptr = (*ptr).next;
    }
    return 0;
}
