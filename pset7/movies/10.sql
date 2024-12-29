SELECT name FROM movies
JOIN directors ON movies.id = directors.movie_id
JOIN ratings ON movies.id = ratings.movie_id
JOIN people ON people.id = directors.person_id
WHERE ratings.rating >= 9 GROUP BY(people.name);

