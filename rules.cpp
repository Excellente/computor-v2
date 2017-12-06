valid variable instructions
    a = 2 -> assigns 2 to a :: DONE
    a -> returns the value stored in a :: DONE
    a = expression :: DONE
    a + 2 = ? -> returns value of the exp ::DONE

to be handled:

    -> a + = ? // for matrices
    -> different data types
    -> scan tree for errors : semantic analyzer

Working test cases:
$> a
$> -1 + 2
$> a = 2
$> a = (1)
$> a = a + 2
$> a + 3 = ?
$> b = a + 5 - 1
$> b = a + a - 3 + 4 - 1
$> a = a * b - 1
$> a + a - (3 + 4 + (1 - a))
$> a * b = ?
$> a * b - (3 + (4 - 2)) = ?
$> a = b / (2 -  1)
$> d = c * a / 6 - 3
$> a = f(x) //segfault if f(x) hasn't been declared : fixed
$> leading sign //ignore if tmp is = and next is +|- and next is num|name: fixed

Test cases to fix:
$> a = ? // var / expression resolution
2/0 = ?