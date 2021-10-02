import geocoder

g = geocoder.ip('me')

print("You live in {}, {}".format(g.city , g.country))