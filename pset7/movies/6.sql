SELECT AVG(rating) AS media_filmes_2012 from movies
JOIN ratings ON movies.id = ratings.movie_id
WHERE movies.year = 2012;
