import mechanize

range_n = 8
pattern = 2 ** range_n

login_page = 'http://ec2-54-92-0-56.ap-northeast-1.compute.amazonaws.com/~icpc2014/common/login_ja.php'
prog_page = 'http://ec2-54-92-0-56.ap-northeast-1.compute.amazonaws.com/~icpc2014/common/workplace_ja.php'
br = mechanize.Browser()
br.set_handle_robots(False)

# Login 
br.open(login_page)
br.select_form(nr=0)
br["team_id"] = "181"
br["pass"] = "EnrU1LdE"
br.submit()

for i in range(pattern):
	# Access program page, and Submit
	br.open(prog_page)
	br.select_form(nr=0)
	br.form['problem'] = ['M'] #controls[0]

	br.form.controls[1].add_file(open("out_"+str(i)), "text/plain", "out_"+str(i))
	br.form.controls[2].add_file(open("m_"+str(i)+".cc"), "text/plain", "m_"+str(i)+".cc")
	br.submit()

	# Access Result page, and Response
	response = br.response()
	html_str = response.read()
	if "<p class=result>Wrong answer.</p>" in html_str:
		print "Wrong answer: ", i
	else:
		print "Correct Answer: ", i
		break
	response.close()

