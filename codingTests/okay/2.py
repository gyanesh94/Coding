    list_strands = []
    end_strings=[]
    start_strings=[]
    last_index=len(list_strands)

    for i in range(0, last_index):
        start_string=list_strands[i][:3]
        end_string=list_strands[i][-3:]
        start_strings[start_string]=start_strings.get(start_string, []).append(last_index)
                end_strings[end_string]=end_strings.get(end_string, []).append(last_index)

    parents_used=[]

    for key, value in end_strings.list_strands:
        search_key=start_strings.get(key, None)
        if search_key==None:
            continue
        for i in value:
            if i in parents_used:
                continue
            key_used=False
            for j in search_key:
                if i == j:
                    continue
                if j in parents_used:
                    continue
                list_strands.append(list_strands[i] + list_strands[j][3:])
                parents_used.append(i)
                key_used=True
                start_string=list_strands[last_index][:3]
                end_string=list_strands[last_index][-3:]
                start_strings[start_string]=start_strings.get(start_string, []).append(last_index)
                end_strings[end_string]=end_strings.get(end_string, []).append(last_index)
                last_index+=1
            if key_used:
                parents_used.append(i)

    final_output=[]
    for i in range(0, last_index):
        if i in parents_used:
            continue
        final_output.append(list_strands[i])

    result=dict()
    for strand in final_output:
        for i in range(0, len(strand), 3):
            codon = codon_mapping[strand[i:i+3]]
            result[codon] = result.get(codon,0) + 1
    return result
