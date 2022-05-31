
/* 
    Theroy and syntax of type-casting. 

    Expression: Definition: Any vaild combination of 
    opeartors and operands is known as an expression. 

    Expressions often involve variables! 
    Therefore the exact value of an expression may not 
    evaluated at the time of compilation. 

    10 + 20 -> This RHS expression can be evaluated statically. 
    a + b   ->  If values of a and b are not determined statically 
                but dynamically then the exact value of a + b 
                cannot determined statically! 
    
    Problem: Although the compiler knows that it cannot know the value 
    of a + b at the time of compilation, it has a responsibility 
    to evaluate the type of a + b at statically? 

    Why? Because in case of assignment statement 

    c = a + b; 

    the compiler MUST know the type of a + b before it can compare it with 
    the type of c! 

    Monologue of compiler: 
    value of a and value of b may not be known to me! 
    But what I know for sure are types of a and b 

    a   :   int 
    b   :   int 
    a+b :   int 
    a*b 

    int a; 
    int b; 
    int c; 

    printf("Enter a:"); 
    scanf("%d", &a);    // 20, 2**30
    printf("Enter b:"); 
    scanf("%d", &b);    // 30, 2**30

    c = a * b; 

    int a; 
    int b; 
    int c1
    long c2;
    int flag_c1 = 0 
    if(a*b >= pow(2, 31) - 1) 
        c1 = a * b; 
    else 
        c2 = a * b; 
    ---------------------------------

    The C compiler infers the type of 
    RHS as well as LHS expressions 
    based on the types of the operands, 
    operators involved in the expression 
    and by applying the meaning of 
    operator in the context of type! 


    Let expr be an expression. 
    Let Ti be its inferred type! 

    a-> int 
    b-> int 
    a + b-> int (Ti)

    (Tc)expr

    (float)(a+b); 

    (Tc)expr

    OPERATOR((Tc)expr)

    OPERATOR((Tc)expr); 

    -> eval(expr) -> address
    -> value -> Ti

    int* p = &n; 

    p + 1 

    a + b

    OPERATOR((Tc)expr) 

    OPERATOR(expr)

    Cup -> tea 

    Tea cup; 

    SMELL(Cup) -> elated. 

    Sweage cup1; 

    (Tea)cup1 -> elated
------------------------------------
    5L                  TaxCat0
    6L-10L  ->   10%    TaxCat1
    10L-20L ->   20%    TaxCat2
    20L->   ->   30%    TaxCat3

    expr
    yogeshwar TaxCat2
    
    ((TaxCat1)yogeshwar)->PayTax

    x * .20
    x * .10
    
*/ 



