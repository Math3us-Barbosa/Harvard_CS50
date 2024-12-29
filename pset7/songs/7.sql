SELECT AVG(energy) AS media_energia FROM songs
JOIN artists ON songs.artist_id = artists.id
WHERE artists.name = "Drake";
