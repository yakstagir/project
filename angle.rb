require 'gnuplot'
include Math
string = File.open("#{ARGV[0]}")
while (str = string.gets)
	str = str.split(" ")
	p a = str[0].to_f
	p b = str[1].to_f
	p angle = asin(a/b)*180/PI

    # tryout gnuplot
    Gnuplot.open do |gp|
      Gnuplot::Plot.new( gp ) do |plot|
 
        plot.xrange "[-10:10]"
        plot.title  "Sin Wave Example"
        plot.ylabel "x"
        plot.xlabel "sin(x)"
 
        plot.data << Gnuplot::DataSet.new( "sin(x)" ) do |ds|
          ds.with = "lines"
          ds.linewidth = 4
        end
 
      end
    end
 
end
