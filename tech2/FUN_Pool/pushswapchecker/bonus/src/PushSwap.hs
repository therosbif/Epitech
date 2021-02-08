--
-- EPITECH PROJECT, 2021
-- B-FUN-300-LYN-3-1-pushswapchecker-jack.goodall
-- File description:
-- PushSwap
--

module PushSwap where

import Sort ( pushA, swap, isSorted )

mySort :: ([Int], [Int]) -> String
mySort ([], []) = ""
mySort (la, [])
  | isSorted la = ""
  | length la > 1 && head la > la !! 1 =
      "sa " ++ mySort (swap la, [])
  | otherwise =
      take (3 * length la) (cycle "pb ") ++ mySort ([], reverse la)
mySort (la, lb)
  | length la > 1 && head la > la !! 1  =
      "sa " ++ mySort (swap la, lb)
  | length lb < 2 || head lb >= lb !! 1 =
      "pa " ++ mySort (pushA (la, lb))
  | otherwise =
      "sb " ++ mySort (la, swap lb)
