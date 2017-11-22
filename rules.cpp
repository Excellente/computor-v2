valid variable instructions
    a = 2 -> assigns 2 to a :: DONE
    a -> returns the value stored in a :: DONE
    a = expression :: DONE
    a + 2 = ? -> returns value of the exp ::DONE

to be handled:
    -> -1 + 2
    -> different data types
    -> brackets in expressions
    -> scan tree for errors : semantic analyzer

Working test cases:
$> a
$> a = 2
$> a = (1)
$> a = a + 2

Tested cases:
// a = - (1)
// $> b = 4
// $> c = a * b + 5 - 1
// $> c
// $> d = c * a / 6 - 3
// $> b = a + b - 1
// $> a = -1