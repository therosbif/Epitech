--
-- EPITECH PROJECT, 2021
-- pushswap_checker
-- File description:
-- Sort
--

module Sort where

swap :: [Int] -> [Int]
swap []             = []
swap [la]           = [la]
swap (a:la:lla)     = la:a:lla

rotate :: [Int] -> [Int]
rotate  []          =  []
rotate [la]         = [la]
rotate  la          = tail la ++ [head la]

rrotate :: [Int] -> [Int]
rrotate  []         =  []
rrotate [la]        = [la]
rrotate  la         = last la : init la

pushA :: ([Int], [Int]) -> ([Int], [Int])
pushA (la, [])      = (la, [])
pushA (la, lb)      = (head lb : la, tail lb)

pushB :: ([Int], [Int]) -> ([Int], [Int])
pushB ([], lb)      = ([], lb)
pushB (la, lb)      = (tail la, head la : lb)


doOps :: [String] -> ([Int], [Int]) -> ([Int], [Int])
doOps  _         ([], [])   = ([], [])
doOps ("sa" : is)  (la, lb) = doOps is (swap la, lb)
doOps ("sb" : is)  (la, lb) = doOps is (la, swap lb)
doOps ("sc" : is)  (la, lb) = doOps is (swap la, swap lb)

doOps ("pa" : is)   lalb    = doOps is (pushA lalb)
doOps ("pb" : is)   lalb    = doOps is (pushB lalb)

doOps ("ra" : is)  (la, lb) = doOps is (rotate la, lb)
doOps ("rb" : is)  (la, lb) = doOps is (la, rotate lb)
doOps ("rr" : is)  (la, lb) = doOps is (rotate la, rotate lb)

doOps ("rra" : is) (la, lb) = doOps is (rrotate la, lb)
doOps ("rrb" : is) (la, lb) = doOps is (la, rrotate lb)
doOps ("rrr" : is) (la, lb) = doOps is (rrotate la, rrotate lb)

doOps [] lalb = lalb
doOps _ _  = ([], [])


------------Sort Test-------------

isSorted :: [Int] -> Bool
isSorted (x : xx : xs) = (x <= xx) && isSorted (xx : xs)
isSorted _ = True
