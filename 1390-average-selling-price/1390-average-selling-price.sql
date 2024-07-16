# Write your MySQL query statement below
select Prices.product_id, ifnull(round(sum(Prices.price * UnitsSold.units) / sum(UnitsSold.units), 2), 0) as average_price from prices left join UnitsSold
on prices.product_id = UnitsSold.product_id and UnitsSold.purchase_date BETWEEN prices.Start_date and prices.end_date group by product_id;