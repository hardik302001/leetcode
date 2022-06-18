/*
Let's say all buy/sell pairs are represented as (b1, s1), (b2, s2), ... (bn, sn) then what we are looking for is (s1 - b1) + (s2 - b2) + ... (sn - bn). Because of associativity we can remove all parenthesis and shuffle all operands any way we want without affecting the final sum, so there is no need to pick up the buy price for the corresponding sell price.

*/

SELECT Distinct(stock_name), SUM(
    CASE
        WHEN operation = 'Buy' THEN -price
        ELSE price
    END
) AS capital_gain_loss
FROM Stocks
GROUP BY stock_name