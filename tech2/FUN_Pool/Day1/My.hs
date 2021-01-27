--
-- EPITECH PROJECT, 2021
-- B-FUN-300-LYN-3-1-funPoolDay1-jack.goodall
-- File description:
-- My
--

------------ Step 1 -------------

mySucc :: Int -> Int
mySucc i =
  i + 1

myIsNeg :: Int -> Bool
myIsNeg i =
  i < 0

myAbs :: Int -> Int
myAbs i =
  if i < 0 then - i else i

myMin :: Int -> Int -> Int
myMin i j =
  if i < j then i else j

myMax :: Int -> Int -> Int
myMax i j =
  if i > j then i else j

------------ Step 2 -------------

myTuple :: a -> b -> (a, b)
myTuple a b =
  (a, b)

myTruple :: a -> b -> c -> (a, b, c)
myTruple a b c =
  (a, b, c)

myFst :: (a, b) -> a
myFst (a, _) =
  a

mySnd :: (a, b) -> b
mySnd (_, b) =
  b

mySwap :: (a, b) -> (b, a)
mySwap (a, b) =
  (b, a)

------------ Step 3 -------------

myHead :: [a] -> a
myHead (a : _) = a
myHead _ = error "myHead : List is Empty"

myTail :: [a] -> [a]
myTail (_ : a) = a
myTail _ = error "MyTail : List is Empty"

myLength :: [a] -> Int
myLength (_ : a) =
  1 + myLength a
myLength _ = 0

myNth :: [a] -> Int -> a
myNth (a : b) i
  | i < 0 = error "myNth : Negative Index"
  | i > 0 = myNth b (i - 1)
  | otherwise = a
myNth _ _ = error "myNth : Index Too Large"

myTake :: Int -> [a] -> [a]
myTake n (a : b)
  | n > myLength (a : b) = a : b
  | n < 0 = error "myTake : Negative Index"
  | n > 0 = a : myTake (n - 1) b
  | otherwise = []
myTake _ _ = []

myDrop :: Int -> [a] -> [a]
myDrop n (a : b)
  | n > myLength (a : b) = []
  | n < 0 = error "myDrop : Negative Index"
  | n > 0 = myDrop (n - 1) b
  | otherwise = a : b
myDrop _ _ = []

myAppend :: [a] -> [a] -> [a]
myAppend (a : b) (c : d) =
  myAppend
    (myInit (a : b))
    (myLast (a : b) : (c : d))
myAppend _ (c : d) = c : d
myAppend (a : b) _ = a : b
myAppend _ _ = []

myReverse :: [a] -> [a]
myReverse (a : b) =
  myLast (a : b) : myReverse (myInit (a : b))
myReverse _ = []

myInit :: [a] -> [a]
myInit (a : b) =
  myTake (myLength (a : b) - 1) (a : b)
myInit _ = error "myInit : List is Empty"

myLast :: [a] -> a
myLast (a : b) =
  myNth (a : b) (myLength (a : b) - 1)
myLast _ = error "myLast : List is empty"

myZip :: [a] -> [b] -> [(a, b)]
myZip (a : b) (c : d) =
  if myLength (a : b) > 0 && myLength (c : d) > 0
    then (a, c) : myZip b d
    else []
myZip _ _ = []

myUnzip :: [(a, b)] -> ([a], [b])
myUnzip [] = ([], [])
myUnzip ((a, b) : xs) =
  let tuple = myUnzip xs
   in (a : myFst tuple, b : mySnd tuple)

------------ Step 4 -------------

myMap :: (a -> b) -> [a] -> [b]
myMap func (a : b) =
  func a : myMap func b
myMap _ _ = []

myFilter :: (a -> Bool) -> [a] -> [a]
myFilter func (a : b) =
  if func a
    then a : myFilter func b
    else myFilter func b
myFilter _ _ = []

myFoldl :: (b -> a -> b) -> b -> [a] -> b
myFoldl func n (a : b) =
  let x = func n a
   in myFoldl func x b
myFoldl _ n _ = n

myFoldr :: (a -> b -> b) -> b -> [a] -> b
myFoldr func n (a : b) =
  let x = func (myLast (a : b)) n
   in myFoldr func x (myInit (a : b))
myFoldr _ n _ = n

myPartition :: (a -> Bool) -> [a] -> ([a], [a])
myPartition func (a : b) =
  let part = myPartition func b
   in if func a
        then (a : myFst part, mySnd part)
        else (myFst part, a : mySnd part)
myPartition _ _ = ([], [])

-----------------Quick Sort--------------

mySortPartition :: (Eq a) => (a -> a -> Bool) -> [a] -> a -> ([a], [a])
mySortPartition func (a : b) c =
  let part = mySortPartition func b c
   in if func a c || a == c
        then (a : myFst part, mySnd part)
        else (myFst part, a : mySnd part)
mySortPartition _ _ _ = ([], [])

myIsSorted :: (Eq a) => (a -> a -> Bool) -> a -> [a] -> Bool
myIsSorted func c (a : b) =
  if a /= c
    then func c a && myIsSorted func a b
    else myIsSorted func a b
myIsSorted _ _ _ = True

myQuickSort :: (Eq a) => (a -> a -> Bool) -> [a] -> [a]
myQuickSort func arr =
  let (c, d) = mySortPartition func arr (myHead arr)
      e = if myIsSorted func (myHead c) (myDrop 1 c)
          then c
          else myQuickSort func (myLast c : myInit c)
      f = if myIsSorted func (myHead d) (myDrop 1 d)
          then d
          else myQuickSort func (myLast d : myInit d)
   in myAppend e f
