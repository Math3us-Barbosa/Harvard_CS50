SELECT DISTINCT p.name FROM stars
JOIN people AS p ON stars.person_id = p.id
WHERE stars.movie_id IN (SELECT movie_id FROM stars
    JOIN people ON stars.person_id = people.id
    WHERE people.name = 'Kevin Bacon'
)AND p.name != 'Kevin Bacon';
