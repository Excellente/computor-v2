valid variable instructions
    a = 2 -> assigns 2 to a :: DONE
    a -> returns the value stored in a :: DONE
    a = expression :: DONE
    a + 2 = ? -> returns value of the exp ::DONE

to be handled:
    -> -1 + 2
    -> a + = ?
    -> different data types
    -> brackets in expressions
    -> scan tree for errors : semantic analyzer

Working test cases:
$> a
$> a = 2
$> a = (1)
$> a = a + 2
$> a + 3 = ?

Tested cases:
// a = - (1)
// $> c = a * b + 5 - 1
// $> c
// $> d = c * a / 6 - 3
// $> b = a + b - 1
// $> a = -1

Investigate
$> a = 1
1
$> b = a - 1
0
$> b = a + 5 - 1
5
$> a
1
$> b = b - 1
4
$> b = a + 5 - 1
5
$> b = a + a - 3 + 4 - 1
-4
$> a = a * b - 1
5
$> a = 2 - 4
-2
$> a = a - 1
-3