

SELECT wt1.Id as 'Id'
FROM Weather wt1, Weather wt2
WHERE wt1.temperature > wt2.temperature AND 
      TO_DAYS(wt1.recordDate)-TO_DAYS(wt2.recordDate)=1;
      
      
      
# TO_DAYS(wt1.DATE) return the number of days between from year 0 to date DATE
# TO_DAYS(wt1.DATE)-TO_DAYS(wt2.DATE)=1 check if wt2.DATE is yesterday respect to wt1.DATE

