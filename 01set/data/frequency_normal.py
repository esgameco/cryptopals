import json

with open('lf.json') as f:
    j = json.load(f)
    total = sum(j.values())
    for key in j.keys():
        j[key] /= total
    json.dump(j, open('lfn.json', 'w'))