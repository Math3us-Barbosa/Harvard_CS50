SELECT COUNT (title) from movies
JOIN ratings ON movies.id = ratings.movie_id
WHERE ratings.rating = 10;
