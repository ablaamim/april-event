import requests

# Get user input for a character name
pokemon_name = input("Enter the name of a Pokemon: ").lower()

# Make a request to the PokeAPI to get information about the character
api_url = f"https://pokeapi.co/api/v2/pokemon/{pokemon_name}"
response = requests.get(api_url)

# Check if the API request was successful
if response.status_code == 200:
    # Parse the response data as JSON
    pokemon_data = response.json()

    # Print the character's name and abilities
    print(f"Name: {pokemon_name.title()}")
    print("Abilities:")
    abilities = pokemon_data['abilities']
    for ability in abilities:
        print(f"- {ability['ability']['name'].title()}")
else:
    print("Error: Invalid Pokemon name entered.")