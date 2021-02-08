--
-- EPITECH PROJECT, 2021
-- pushswap_checker
-- File description:
-- Sort
--

module DoOp where

import Sort

doOp :: String -> ([Int], [Int]) -> ([Int], [Int])
doOp "sa"  (la, lb) = (swap la, lb)
doOp "sb"  (la, lb) = (la, swap lb)
doOp "sc"  (la, lb) = (swap la, swap lb)

doOp "pa"   lalb    = pushA lalb
doOp "pb"   lalb    = pushB lalb

doOp "ra"  (la, lb) = (rotate la, lb)
doOp "rb"  (la, lb) = (la, rotate lb)
doOp "rr"  (la, lb) = (rotate la, rotate lb)

doOp "rra" (la, lb) = (rrotate la, lb)
doOp "rrb" (la, lb) = (la, rrotate lb)
doOp "rrr" (la, lb) = (rrotate la, rrotate lb)
