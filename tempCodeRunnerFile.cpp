ze();i++) {
        cout<<i<<" rolls: -----------------------"<<endl;
        for (Result r: results[i]) {
            if (r.position>0) {
                w_chances[r.rolls][r.position] += r.chance;
            } else if (r.position == 0) {
                start_chances[r.rolls]+=r.chance;
            } else {
                l_chances[r.rolls][-r.position] += r.chance;
            }
            cout<<r.rolls<<" "<<r.chance<<" "<<r.position<<endl;
        }
    }