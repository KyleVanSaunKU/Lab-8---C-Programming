temperature_convert = temperature_convert
score_combinations = score_combinations

temperature_convert_file = temperature_convert.c
score_combinations_file = score_combinations.c
all: $(temperature_convert) $(score_combinations)

$(temperature_convert): $(temperature_convert_file)
	-o $(temperature_convert) $(temperature_convert_file)

$(score_combinations): $(score_combinations_file)
	-o $(score_combinations) $(score_combinations_file)

clean:
	rm -f $(temperature_convert) $(score_combinations)
