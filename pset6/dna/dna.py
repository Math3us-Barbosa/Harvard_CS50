import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("There must be 3 command-line arguments")
        sys.exit(1)
    # TODO: Read database file into a variable
    with open(sys.argv[1], "r") as file:
        reader = csv.DictReader(file)
        sequences = reader.fieldnames[1:]
        database = list(reader)
    # TODO: Read DNA sequence file into a variable

    with open(sys.argv[2], "r") as f:
        dna_sequence = f.read()
    # TODO: Find longest match of each STR in DNA sequence
    reps = {}
    for seq in sequences:
        reps[seq] = (longest_match(dna_sequence, seq))
    # TODO: Check database for matching profiles
    for row in database:
        for seq in sequences:
            found = True
            if int(row[seq]) != int(reps[seq]):
                found = False
                break
        if (found == True):
            print(f"{row["name"]}.")
            sys.exit(0)
    print("No match.")
    return

# Now you can use fieldnames as a parameter for the longest_match method


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
