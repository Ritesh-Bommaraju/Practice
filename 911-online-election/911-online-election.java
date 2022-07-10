class TopVotedCandidate {
    Map<Integer, Integer> cachedLeader = new HashMap(); // key: time, value: leader at `time`, could also use a parallel int[] here with same size as persons
    int[] times; // store all times for the lookup of a floor time given any random time point.
    
    public TopVotedCandidate(int[] persons, int[] times) {
        this.times = times;
        int N = persons.length;
        int leader = -1;
        Map<Integer, Integer> votesCounter = new HashMap(); // key: person, value: num of votes
        for (int i = 0; i < N; i++) {
            // get current person id and time id
            int person = persons[i];
            int time = times[i];
            // update votesCounter
            votesCounter.put(person, votesCounter.getOrDefault(person, 0) + 1);
            // update leader if we've seen any change in the order
            if (leader == -1 || votesCounter.get(person) >= votesCounter.get(leader)) leader = person;
            cachedLeader.put(time, leader);
        }
    }

    public int q(int t) {
        return cachedLeader.get(getFloorTime(t));
    }
    
    // util fuction to get the floor time 
    private int getFloorTime(int time) {
        int i = Arrays.binarySearch(times, time);
        int floorIdx = i < 0 ? (- i - 2) : i;
        return times[floorIdx];
    }
}
/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj.q(t);
 */